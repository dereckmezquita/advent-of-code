box::use(data.table)

dt <- data.table$fread("./2023/data/20231201-trebuchet.txt", header = FALSE)

getNum <- function(val) {
    indices <- gregexpr("[0-9]", val)

    return(sapply(seq_along(indices), function(i) {
        idx <- indices[[i]]
        cur_val <- val[i]

        bol <- substr(cur_val, idx, idx)
        eol <- substr(cur_val, idx[length(idx)], idx[length(idx)])
        return(as.numeric(paste0(bol, eol)))
    }))
}

main <- function() {
    dt[, score := getNum(V1)]
    sum(dt$score)   
}
# ----
con <- file("./2023/data/20231201-trebuchet.txt", "r")

lines <- readLines(con)
close(con)

process_lines <- function(lines) {
    # Extract numbers and convert to numeric
    numbers <- gsub("[a-z]", "", lines)

    # get the first and last digit of each number
    first_digit <- substr(numbers, 1, 1)
    last_digit <- substr(numbers, nchar(numbers), nchar(numbers))

    num <- as.numeric(paste0(first_digit, last_digit))
    
    # Process and sum the numbers
    print(sum(num))
}

options(scipen = 999)
print(microbenchmark::microbenchmark(
    process_lines(lines),
    times = 10
), unit = "s")