fun pr(ans:String) {
    println(ans)
}

fun work() {
    var xy = 0
    var dy = 0
    val nowString = readLine()
    if (nowString != null) {
        for (element in nowString) {
            when (element) {
                '>' -> dy++
                '<' -> xy++
            }
        }
    }
    if (xy == 0 && dy == 0)
        println("=")
    else if (xy != 0 && dy != 0)
        println("?")
    else if(dy == 0 && xy != 0)
        println("<")
    else
        println(">")
}

fun main() {
    var t = readLine()?.toInt()
    if (t != null)
        while (--t >= 0) {
            work()
        }

}


