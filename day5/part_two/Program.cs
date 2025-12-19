namespace part_two;

class Program {
    static void Main(string[] args) {
        using StreamReader sr = new StreamReader("input.txt");

        string file = sr.ReadToEnd();
        string[] p1 = file.Split("\n\n")[0].Split('\n');

        long[][] ranges = new long[p1.Length][];
        for (int i = 0; i < p1.Length; i++) {
            ranges[i] = new long[2];
            ranges[i][0] = long.Parse(p1[i].Split('-')[0]);
            ranges[i][1] = long.Parse(p1[i].Split('-')[1]);
        }

        var ordered = ranges
                .Select((arr, idx) => new { arr, idx })
                .OrderBy(x => x.arr[0])
                .ThenBy(x => x.idx)
                .Select(x => x.arr)
                .ToArray();

        long v = 0;
        long cs = ordered[0][0];
        long ce = ordered[0][1];

        for (int i = 1; i < ordered.Length; i++) {
            if (ordered[i][0] <= ce + 1) {
                if (ordered[i][1] > ce) {
                    ce = ordered[i][1];
                }
            } else {
                v += ce - cs + 1;
                cs = ordered[i][0];
                ce = ordered[i][1];
            }
        }

        v += ce - cs + 1;
        Console.WriteLine(v);
    }
}