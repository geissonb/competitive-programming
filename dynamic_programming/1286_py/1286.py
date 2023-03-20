while True:

	N = int(input())

	if N == 0:
		break

	P = int(input())

	p = []
	w = []
	itens_mochila = dict()
	aux = []

	for i in range(N):
		a, b = input().split(' ')
		p.append(int(a))
		w.append(int(b))

	mochila = [[0 for j in range(0, P+1, 1)] for i in range(0, N+1, 1)]

	for capacidade in range(0, P+1, 1):
		for item in range(0, N+1, 1):

			if item == 0:
				itens_mochila[item, capacidade] = []
				continue

			else:
				x = mochila[(item-1)][capacidade]
				aux = itens_mochila[item-1, capacidade].copy()

				if capacidade-w[item-1] >= 0:
					y = mochila[(item-1)][(capacidade-w[(item-1)])] + p[(item-1)]

					if x < y:
						x = y
						aux = itens_mochila[item-1, capacidade-w[item-1]].copy()
						aux.append(p[item-1])

				itens_mochila[item, capacidade] = aux.copy()
				aux.clear()

			mochila[item][capacidade] = x

	print(str(mochila[N][P])+" min.")
	print(itens_mochila[N, P])

	mochila.clear()
	p.clear()
	w.clear()
	itens_mochila.clear()
