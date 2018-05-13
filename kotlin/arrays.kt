
fun main(args: Array<String>) {
    val numbers: IntArray= intArrayOf(1,10,20,30,40,50)
    val x = numbers[0]
    val y = 10
    if (x in 1..y - 1)
        println("OK")

    for (a in 1..5)
        print("${a} ")

    if (10 in numbers)
        println("Yes: array contains 10")

    if (20 in numbers)
        println("Yes: array contains 20")
    else
        println("No: array doesn't contains 20")
}
