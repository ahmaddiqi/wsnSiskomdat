from sklearn.tree import DecisionTreeClassifier
import pandas as pd
from sklearn.datasets import load_iris
from micromlgen import port
data = pd.read_csv('decisiontree/dataset.csv')
print(data)
x = data[['pH', 'DO', 'suhu' ]]
y = data ['class']
#model decision tree
tree_model = DecisionTreeClassifier()
#training model data
tree_model.fit(x,y)
fileDecision= open("decisiontree.h","w+")
fileDecision.write(port(tree_model))
fileDecision.close()