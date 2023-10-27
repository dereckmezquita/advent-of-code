
dive <- data.table::fread("./data/20211202-dive.txt")

# part one
sum(dive[V1 == "forward", ]$V2)

dive[, V2 := data.table::fifelse(V1 == "up", V2 * -1, V2)]

sum(dive[V1 != "forward", ]$V2)

# part two
