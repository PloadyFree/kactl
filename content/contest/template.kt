/**
 * Author: Musin
 * Source: Head
 * Date: 2021-03-23
 * Description:
 */

const val YANDEX = false
const val FORCE_LOCAL = false
val OJ = !FORCE_LOCAL && (YANDEX || System.getProperty("ONLINE_JUDGE") != null)

val LOCAL = !OJ

fun main() {
    Locale.setDefault(Locale.US)
    val fin = if (OJ) {
//        val name: String? = "galaxy"
//        System.setOut(PrintStream(BufferedOutputStream(FileOutputStream("$name.out"))))
//        FastReader("$name.in")
        System.setOut(PrintStream(BufferedOutputStream(System.out)))
        FastReader()
    } else {
        FastReader()
    }
    Task(fin).solve()
    System.out.flush()
}

class Task(private val fin: FastReader = FastReader()) {
    fun solve() {
    }
}

class FastReader(fileName: String? = null) {
    @JvmField
    val br = BufferedReader(if (fileName != null) FileReader(fileName) else InputStreamReader(System.`in`))

    @JvmField
    var st = StringTokenizer("")

    fun readString(): String {
        while (!st.hasMoreTokens()) st = StringTokenizer(br.readLine())
        return st.nextToken()
    }
}