// O(n) optimized
func twoSum(nums []int, target int) []int {
	// hash stores value -> index
	hash := make(map[int]int)

	for i := 0; i <= len(nums); i++ {
		// check if solution exists in hash

		j, ok := hash[target-nums[i]]

		if ok {
			return []int{j, i}
		}

		// store current number into hash
		hash[nums[i]] = i
	}

	// Should never reach this point
	return []int{}
}

// O(n^2) brute force
func twoSum2(nums []int, target int) []int {
	for i := 0; i <= len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	// Should never reach this point
	return []int{}
}