namespace part_one;

class Program {
    static void Main(string[] args) {
        using StreamReader sr = new StreamReader("input.txt");

        string file = sr.ReadToEnd();
        string[] p1 = file.Split("\n\n")[0].Split('\n');
        string[] p2 = file.Split("\n\n")[1].Split('\n');
        
        long[][] ranges = new long[p1.Length][];
        for (int i = 0; i < p1.Length; i++) {
            ranges[i] = new long[2];
            ranges[i][0] = long.Parse(p1[i].Split('-')[0]);
            ranges[i][1] = long.Parse(p1[i].Split('-')[1]);
        }

        int f = 0;
        for (int i = 0; i < p2.Length; i++) {
            long value = long.Parse(p2[i]);

            foreach (var v in ranges) {
                if (value >= v[0] && value <= v[1]) {
                    f++;
                    break;
                }
            }
        }

        Console.WriteLine(f);
    }
}
