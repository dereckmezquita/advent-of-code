con <- file("./2023/data/20231201-trebuchet.txt", "r")

main <- function() {
    sum <- 0
    while (TRUE) {
        line <- readLines(con, n = 1)
        if (length(line) == 0) break

        indices <- gregexpr("[0-9]", line)[[1]]

        last_idx <- indices[length(indices)]
        bol <- substr(line, indices, indices)
        eol <- substr(line, last_idx, last_idx)
        sum <- sum + as.numeric(paste0(bol, eol))
    }
    print(sum)
}

options(scipen = 999)
print(microbenchmark::microbenchmark(
    main(),
    times = 1
), unit = "s")