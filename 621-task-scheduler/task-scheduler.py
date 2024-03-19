class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        
        if n == 0:
            return len(tasks)

        counter = Counter(tasks)
        maxValue = max(counter.values())
        maxCount = list(counter.values()).count(maxValue)
            
        return max((n + 1) * (maxValue - 1) + maxCount, len(tasks))