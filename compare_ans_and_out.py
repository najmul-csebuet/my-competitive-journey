# write a python script to compare the output of the program with the expected output
# in.txt is the input file
# out.txt is the output file
# ans.txt is the expected output file
# no need to take file names as input.

# compare_outputs.py

def compare_outputs():
    with open('out.txt', 'r') as out_file, open('ans.txt', 'r') as ans_file:
        out_lines = [line.strip() for line in out_file.readlines()]
        ans_lines = [line.strip() for line in ans_file.readlines()]

    if out_lines == ans_lines:
        print("Output matches expected output ✅")
    else:
        print("Output does NOT match expected output ❌")
        print("\nDifferences:")
        max_lines = max(len(out_lines), len(ans_lines))
        for i in range(max_lines):
            out_line = out_lines[i] if i < len(out_lines) else "<no output>"
            ans_line = ans_lines[i] if i < len(ans_lines) else "<no expected output>"
            if out_line != ans_line:
                print(f"Line {i + 1}:\n  Expected: {ans_line}\n  Got:      {out_line}")

if __name__ == "__main__":
    compare_outputs()
