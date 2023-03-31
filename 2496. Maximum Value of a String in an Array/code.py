class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        ans = -99999
        for str in strs:
            if str.isdigit():
                ans = max(ans, int(str))
            else: ans = max(ans, len(str))
        return ans
