from itertools import permutations
import subprocess

n = 5

for perm in permutations(range(n)):
	result = subprocess.run(
		["./push_swap", *map(str, perm)],
		capture_output=True,
		text=True
	)
	arr_str = next((line for line in result.stdout.splitlines() if 'arr' in line), None)
	if arr_str:
		arr = list(map(int, arr_str[arr_str.find('[') + 1:arr_str.find(']')].split()))
		if arr != sorted(arr):
			print(f"{' '.join(map(str, perm))} -> {' '.join(map(str, arr))}")
