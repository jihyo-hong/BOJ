fun main(args: Array<String>) {
    var n: Int = readLine()!!.toInt()
    var gap = 0
    for (i in 2 * n - 1 downTo 1 step(2) ) {
        var p = ""
        for (j in 1..gap)
            p += ' '
        for (j in 1..i)
            p += '*'
        println(p)
        gap++
    }
    gap -= 2
    for (i in 3..2 * n - 1 step(2) ) {
        var p = ""
        for (j in 1..gap)
            p += ' '
        for (j in 1..i)
            p += '*'
        println(p)
        gap--
    }
}