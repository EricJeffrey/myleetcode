
class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        words = sentence.split(' ')
        isprice = [False for _ in words]
        price = [0 for _ in words]
        for i, word in enumerate(words):
            if word.startswith("$") and word[1::].isdigit():
                isprice[i] = True
                price[i] = int(word[1::])
        print(isprice)
        print(price)
        nwords = [word for word in words]
        for i, _ in enumerate(words):
            if isprice[i]:
                nwords[i] = '${:.2f}'.format(price[i] * (100 - discount) / 100)
        return ' '.join(nwords)


if __name__ == "__main__":
    print(Solution().discountPrices(
        "there are $1 $2 and 5$ candies in the shop", 50))
    print(Solution().discountPrices("1 2 $3 4 $5 $6 7 8$ $9 $10$", 100))
    pass
