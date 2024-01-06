con <- file("./2023/data/20231201-trebuchet.txt", "r")

lines <- readLines(con)
close(con)

process_lines <- function(lines) {
    # Extract numbers and convert to numeric
    numbers <- as.numeric(gsub("[^0-9]", "", lines))

    # get the first and last digit of each number
    first_digit <- floor(numbers / 10 ^ (nchar(numbers) - 1))
    last_digit <- numbers %% 10

    num <- paste0(first_digit, last_digit)
    
    # Process and sum the numbers
    print(sum(as.numeric(num)))
}

options(scipen = 999)
print(microbenchmark::microbenchmark(
    process_lines(lines),
    times = 10
), unit = "s")