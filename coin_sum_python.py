# coin sum program redone in python

# goal: optimize too -- use if statements to reduce instances of unecessary loops

print('Calculates all the ways to make $1 with just coins: ')

count = 0

for h in range(0,3):
    if (50*h <= 100):
        for q in range(0,5):
            if (50*h + 25*q <= 100):
                for d in range(0,11):
                    if (50*h + 25*q + 10*d <= 100):
                        for n in range(0,21):
                            if (50*h + 25*q + 10*d + 5*n <= 100):
                                for p in range(0,101):
                                    if (50*h + 25*q + 10*d + 5*n + 1*p == 100):
                                        count = count + 1
                                        print(h, ' h ', q, ' q ', d, ' d ', n, ' n ', p, ' p ')



print('\nThere are',count,'ways to make $1 with just coins.\n')
