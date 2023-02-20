import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	private static int[] m = new int[11];
	private static int[][][][][][][][][][][][] tomato;
	private static int[][] direct = new int[22][];
	private static Queue<int[]> queue = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		// initialize
		for (int i = 0; i < 11; i++) {
			m[i] = Integer.parseInt(st.nextToken());
		}
		tomato = new int[m[0]][m[1]][m[2]][m[3]][m[4]][m[5]][m[6]][m[7]][m[8]][m[9]][m[10]][2];
		for (int i = 0; i < 22; i++) {
			int[] tmp = new int[11];
			tmp[i % 11] = i < 11 ? 1 : -1;
			direct[i] = tmp;
		}
		for (int i10 = 0; i10 < m[10]; i10++) {
			for (int i9 = 0; i9 < m[9]; i9++) {
				for (int i8 = 0; i8 < m[8]; i8++) {
					for (int i7 = 0; i7 < m[7]; i7++) {
						for (int i6 = 0; i6 < m[6]; i6++) {
							for (int i5 = 0; i5 < m[5]; i5++) {
								for (int i4 = 0; i4 < m[4]; i4++) {
									for (int i3 = 0; i3 < m[3]; i3++) {
										for (int i2 = 0; i2 < m[2]; i2++) {
											for (int i1 = 0; i1 < m[1]; i1++) {
												st = new StringTokenizer(br.readLine());
												{
													for (int i0 = 0; i0 < m[0]; i0++) {
														tomato[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][0] = Integer
																.parseInt(st.nextToken());
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		// solution
		for (int i0 = 0; i0 < m[0]; i0++) {
			for (int i1 = 0; i1 < m[1]; i1++) {
				for (int i2 = 0; i2 < m[2]; i2++) {
					for (int i3 = 0; i3 < m[3]; i3++) {
						for (int i4 = 0; i4 < m[4]; i4++) {
							for (int i5 = 0; i5 < m[5]; i5++) {
								for (int i6 = 0; i6 < m[6]; i6++) {
									for (int i7 = 0; i7 < m[7]; i7++) {
										for (int i8 = 0; i8 < m[8]; i8++) {
											for (int i9 = 0; i9 < m[9]; i9++) {
												for (int i10 = 0; i10 < m[10]; i10++) {
													if (tomato[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][0] == 1) {
														queue.offer(new int[] { i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10 });
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		while (!queue.isEmpty()) {
			int[] x = queue.poll();
			for (int d = 0; d < 22; d++) {
				int[] dx = x.clone();
				for (int i = 0; i < 11; i++) {
					dx[i] += direct[d][i];
				}
				if (inRange(dx) && tomato[dx[0]][dx[1]][dx[2]][dx[3]][dx[4]][dx[5]][dx[6]][dx[7]][dx[8]][dx[9]][dx[10]][0] == 0) {
					tomato[dx[0]][dx[1]][dx[2]][dx[3]][dx[4]][dx[5]][dx[6]][dx[7]][dx[8]][dx[9]][dx[10]][0] = 1;
					tomato[dx[0]][dx[1]][dx[2]][dx[3]][dx[4]][dx[5]][dx[6]][dx[7]][dx[8]][dx[9]][dx[10]][1] = 
							tomato[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]][x[8]][x[9]][x[10]][1] + 1;
					queue.offer(new int[] { dx[0], dx[1], dx[2], dx[3], dx[4], dx[5], dx[6], dx[7], dx[8], dx[9], dx[10] });
				}
			}
		}

		// result
		System.out.println(result());
	}

	public static boolean inRange(int[] x) {
		for (int i = 0; i < 11; i++) {
			if (!(0 <= x[i] && x[i] < m[i])) {
				return false;
			}
		}
		return true;
	}

	public static int result() {
		int max = 0;
		for (int i0 = 0; i0 < m[0]; i0++) {
			for (int i1 = 0; i1 < m[1]; i1++) {
				for (int i2 = 0; i2 < m[2]; i2++) {
					for (int i3 = 0; i3 < m[3]; i3++) {
						for (int i4 = 0; i4 < m[4]; i4++) {
							for (int i5 = 0; i5 < m[5]; i5++) {
								for (int i6 = 0; i6 < m[6]; i6++) {
									for (int i7 = 0; i7 < m[7]; i7++) {
										for (int i8 = 0; i8 < m[8]; i8++) {
											for (int i9 = 0; i9 < m[9]; i9++) {
												for (int i10 = 0; i10 < m[10]; i10++) {
													if (tomato[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][0] == 0) {
														return -1;
													}
													if (tomato[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][1] > max) {
														max = tomato[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10][1];
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return max;
	}

}
