import pandas as pd
import matplotlib.pyplot as plt
import sys

g = pd.read_csv(sys.argv[1])
# pd.options.display.mpl_style = 'default'
f1 = g.dropna(thresh=1).plot(kind='scatter', x='x', y='y', s=g['pociones']*15, color = 'DarkRed', label='Gimnasios')
g[pd.isnull(g.pociones)].plot(kind='scatter', x='x', y='y', color = 'DarkBlue', label='Pokeparadas', ax=f1)
leg = plt.legend(loc='best')
plt.show(block=True)