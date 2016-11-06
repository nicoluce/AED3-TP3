import pandas as pd
import matplotlib.pyplot as plt

g = pd.read_csv('grafo.csv')
pd.options.display.mpl_style = 'default'
f1 = g.dropna(thresh=1).plot(kind='scatter', x='x', y='y', s=g['pociones']*25, color = 'DarkRed', label='Gimnasios')
g[pd.isnull(g.pociones)].plot(kind='scatter', x='x', y='y', color = 'DarkBlue', label='Pokeparadas', ax=f1)
plt.show(block=True)