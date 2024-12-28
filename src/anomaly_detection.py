import pandas as pd
from sklearn.ensemble import IsolationForest
import pickle

# Load dataset
data = pd.read_csv("data/keystroke_data.csv")

# Train Isolation Forest Model
model = IsolationForest(contamination=0.1)
data['anomaly'] = model.fit_predict(data[['typing_speed', 'key_interval']])

# Save model
with open("models/anomaly_model.pkl", "wb") as file:
    pickle.dump(model, file)

# Check for the latest anomaly
if data['anomaly'].iloc[-1] == -1:
    print("Anomaly detected!")
