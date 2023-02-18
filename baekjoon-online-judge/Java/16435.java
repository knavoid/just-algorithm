import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static int N; // 과일의 개수
	static int L; // 스네이크버드 초기 길이
	static int[] H; // 나무 

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		H = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			H[i] = Integer.parseInt(st.nextToken());
		}
		
		// solution
		Arrays.sort(H);
		for (int i = 0; i < N; i++) {
			// 가장 짧은 나무보다 길이가 짧으면 더이상 먹지 못함
			if (H[i] > L) {
				break;
			} 
			L++; // 스네이크 버드 길이 증가
		}
		
		// result
		System.out.println(L);
	}

}
