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

res <- microbenchmark::microbenchmark(
    main(),
    times = 10
)


ggplot2::autoplot(res)

print(res, unit = "s")
