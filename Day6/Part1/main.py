import re
winners = [{}]
nums = []
def main():
    with open("input1.txt") as f:
        lines = f.read().splitlines()

    for line in lines:
        print(line)
        print(line[8:])
        for i in range(8, len(line)):
            
        wins, numbers = line[8:].split(" |")
        wins = map(int, re.findall(r'\d+', wins))
        print(wins)
        winners.append(wins)
        nums.append(numbers)
    print(winners)
    print(nums)

if __name__ == "__main__":
    main()
