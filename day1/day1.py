# This problem should be fairly straightforward 
def read_input(file): 
    x = [] 
    y = [] 
    with open(file, 'r') as f:
        for line in f:
            x.append(int(line.split()[0]))
            y.append(int(line.split()[1]))
    return x, y

# Get x and y based on input file 
x, y = read_input('day1/input.txt')

# Sort x and y, per question
x = sorted(x) 
y = sorted(y) 
diff_sum = 0 

# Part 1 
for i in range(len(x)): 
    diff_sum += abs(x[i] - y[i])

# Big O: O(nlogn) - biggest denominator is the sorting of x and y
print(f"Part 1: {diff_sum}")

# Part 2 
# This is also quite easy, you just need the count of y - so use a dictionary 
y_count = {} 
for ele in y: 
    y_count[ele] = y_count.get(ele, 0) + 1

product_sum = 0 
# Get the product of x and y_count
for ele in x: 
    product_sum += ele * y_count.get(ele, 0)

# Big O: O(nlogn) - biggest denominator is the sorting of x and y
print(f"Part 2: {product_sum}")

