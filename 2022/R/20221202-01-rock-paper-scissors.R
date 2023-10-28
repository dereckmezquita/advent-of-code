box::use(data.table)

dt <- data.table$fread("./2022/data/20221202-rock-paper-scissors.txt", col.names = c("opp", "me"))

mapping = list(
    A = 0, X = 0,
    B = 1, Y = 1,
    C = 2, Z = 2
)

dt[, opp := unlist(mapping[opp])]
dt[, me := unlist(mapping[me])]

dt[, result := me - opp]

sum(dt$result)
