library("data.table")
box::use(data.table)

dt <- data.table$fread("./2022/data/20221202-rock-paper-scissors.txt", col.names = c("opp", "me"))

mapping = list(
    A = 0, X = 0,
    B = 1, Y = 1,
    C = 2, Z = 2
)

shapeMapping = list(
    X = 1,
    Y = 2,
    Z = 3
)

getResult <- function(v1, v2) {
    resultMatrix = list(
        list(3, 0, 6),
        list(6, 3, 0),
        list(0, 6, 3)
    )
}

dt[,
    score := getResult(unlist(mapping[me]), unlist(shapeMapping[opp])) + unlist(shapeMapping[me])
]
