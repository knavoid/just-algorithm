import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static int N;
	static List<Integer> from;
	static List<Integer> to;
	
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		// initialize
		N = input.nextInt();
		from = new ArrayList<>();
		to = new ArrayList<>();
		
		// solution
		hanoi(N, 1, 3); // N개의 원판을 1위치에서 3위치로 
		
		// result
		int len = from.size();
		System.out.println(from.size());
		for (int i = 0; i < len; i++) {
			bw.write(from.get(i) + " " + to.get(i) + "\n");
		}
		
		input.close();
		bw.flush();
		bw.close();
	}
	
	static void hanoi(int n, int f, int t) {
		if (n == 1) {
			from.add(f);
			to.add(t);
		} else {
			int a = another(f, t);
			hanoi(n - 1, f, a);
			from.add(f);
			to.add(t);
			hanoi(n - 1, a, t);
		}
	}
	
	// 1, 2, 3 중에서 주어진 x, y가 아닌 숫자를 반환
	static int another(int x, int y) {
		return x + y == 5 ? 1 : x + y == 4 ? 2 : 3; 
	}
	
}
