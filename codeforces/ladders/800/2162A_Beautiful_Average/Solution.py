def solve(a):
    max = a[0]
    for i in range(1, len(a)):
        if a[i] > max:
            max = a[i]
    print(max)


if __name__ == '__main__':
    test_cases = int(input())
    for _ in range(test_cases):
        n = int(input())
        a = [int(x) for x in input().split()]    
        solve(a)