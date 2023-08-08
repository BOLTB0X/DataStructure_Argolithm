def solution(phone_book):
    hashMap = {}

    for phone in phone_book:
        hashMap[phone] = 1

    for phone in phone_book:
        prefix = ""
        for num in phone:
            prefix += num

            if prefix in hashMap and prefix != phone:
                return False
    return True
