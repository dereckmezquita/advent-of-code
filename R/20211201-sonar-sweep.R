
sonar <- data.table::fread("../data/20211201-sonar-sweep.txt")

sonar[
    , shift_one := data.table::fifelse(V1 - data.table::shift(V1, 1L, type = "lag") > 0, TRUE, FALSE)
]

sum(sonar$shift_one[-1])

#--- part two

sonar[
    , three_sum := data.table::frollsum(sonar$V1, 3L)
][
    , three_sum := data.table::fifelse(three_sum - data.table::shift(three_sum, 1L, type = "lag") > 0, TRUE, FALSE)
]

sum(tail(sonar$three_sum, length(sonar$three_sum) - 3))
