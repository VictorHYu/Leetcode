// Slightly optimized
func lengthOfLongestSubstring(s string) int {
	var front, max = 0, 0
	dict := make(map[byte]int)

	for back := 0; back < len(s); back++ {
		// Try to add another character
		// Move front forward until valid
		for {
			val, ok := dict[s[back]]
			if ok && (val >= front) {
				front += 1
			} else {
				break
			}
		}

		dict[s[back]] = back
		length := back - front + 1
		if length > max {
			max = length
		}
	}

	return max
}

func lengthOfLongestSubstring2(s string) int {
	var front, max = 0, 0
	dict := make(map[byte]bool)

	for back := 0; back < len(s); back++ {
		// Try to add another character
		// Move front forward until valid
		for {
			val, ok := dict[s[back]]
			if ok && val {
				dict[s[front]] = false
				front += 1
			} else {
				break
			}
		}

		dict[s[back]] = true
		length := back - front + 1
		if length > max {
			max = length
		}
	}

	return max
}