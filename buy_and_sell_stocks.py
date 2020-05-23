prices = [7, 1, 5, 3, 6, 4]
min_price = 99999999
max_profit = 0
for i in range(len(prices)):
    if prices[i] < min_price:
        min_price = prices[i]
    elif prices[i] - min_price > max_profit:
        max_profit = prices[i] - min_price
print(max_profit)