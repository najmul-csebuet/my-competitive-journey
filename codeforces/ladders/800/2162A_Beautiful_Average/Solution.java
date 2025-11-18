import java.util.Scanner;

class Solution {
  public static void solve(int[] a) {
    int max = a[0];
    for (int i = 1; i < a.length; i++) {
      if (a[i] > max) {
        max = a[i];
      }
    }
    System.out.println(max);
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int testCases = sc.nextInt();
    while (testCases-- > 0) {
      int n = sc.nextInt();
      int[] a = new int[n];
      for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
      }
      solve(a);
    }
    sc.close();
  }
};
