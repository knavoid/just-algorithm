import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	static int S; // DNA 문자열 길이
	static int P; // 부분문자열 길이
	static String DNA; // DNA
	static Map<Character, Integer> ACGT = new HashMap<>();
	static int[] ACGTMin = new int[4]; // 각 필요한 최소 개수
	static int[] ACGTCount = new int[4]; // 개수 저장
	static int answer;
	
	public static void main(String[] args) {
		Scanner input  = new Scanner(System.in);
		
		// initialize
		S = input.nextInt();
		P = input.nextInt();
		DNA = input.next();
		ACGT.put('A', 0); 
		ACGT.put('C', 1);
		ACGT.put('G', 2);
		ACGT.put('T', 3);
		for (int i = 0; i < 4; i++) {
			ACGTMin[i] = input.nextInt();
		}
		input.close();
		
		// 가장 처음 P개의 문자 수 체크
		for (int i = 0; i < P; i++) {
			ACGTCount[ACGT.get(DNA.charAt(i))]++;
		}
		validate();
		
		// 한칸씩 이동하며 카운트 값 변화
		for (int i = 0; i < S - P; i++) {
			ACGTCount[ACGT.get(DNA.charAt(i))]--;
			ACGTCount[ACGT.get(DNA.charAt(i + P))]++;
			validate();
		}
		
		// result
		System.out.println(answer);
	}
	
	static void validate() {
		for (int i = 0; i < 4; i++) {
			if (ACGTCount[i] < ACGTMin[i]) {
				return;
			}
		}
		answer++; // 모든 조건을 만족하는 경우
	}

}
