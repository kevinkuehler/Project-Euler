from collections import defaultdict

def poker(cards):
	h1, r1 = hand_rank(cards[:5]) 
	h2, r2 = hand_rank(cards[5:])
	if r1 > r2: return 1
	elif r1 == r2:
		for c1,c2 in zip(h1, h2):
			if c1[::-1] != c2[::-1]: 
				if c1[::-1] > c2[::-1]: return 1
				break
	return 0

def card_value(x):
    return {'T': 10,'J': 11,'Q': 12,'K': 13,'A': 14}.get(x,ord(x)-48)

def hand_rank(hand):
	freq = defaultdict(int)
	flush = True
	flush_type = hand[0][1]
	for card in hand:
		if flush: flush = flush_type == card[1]
		freq[card_value(card[0])] += 1
	freq = sorted(freq.items(), key=lambda t: (t[1], t[0]), reverse=True)
	if len(freq) == 5:
		straight = (freq[0][0] - freq[-1][0] == 4)*36
		if not straight: # ace wraps
			straight = (freq[-1][0] == 2 and freq[1][0] == 5 and freq[0][0] == 14)*35
		return freq, straight + flush*37
	return freq, max(10*freq[0][1] + 4*freq[1][1], flush*37)		

with open('p054_poker.txt') as f:
    print(sum(poker(line.split()) for line in f ))