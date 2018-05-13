
fun main(args: Array<String>) {
    val numbers : IntArray = intArrayOf(10,20,30,40,50)
    for (arg in numbers)
        println(arg)

    // or
    println()
    for (i in numbers.indices)
        println(numbers[i])
}