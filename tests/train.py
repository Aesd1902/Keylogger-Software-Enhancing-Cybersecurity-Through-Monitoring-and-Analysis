import pandas as pd
from sklearn.ensemble import IsolationForest
import pickle

# Correct path to the data CSV file
data_path = "C:/Users/Uday Alugolu/OneDrive/Desktop/KeyloggerSoftware/data/keystroke_data.csv"

# Load your dataset
data = pd.read_csv(data_path)

# Define the feature columns
features = ['typing_speed', 'key_interval']
X = data[features]

# Initialize and train the model
model = IsolationForest()
model.fit(X)

# Save the trained model to a .pkl file
model_path = "C:/Users/Uday Alugolu/OneDrive/Desktop/KeyloggerSoftware/models/anomaly_model.pkl"
with open(model_path, 'wb') as file:
    pickle.dump(model, file)

print("Model trained and saved successfully.")
