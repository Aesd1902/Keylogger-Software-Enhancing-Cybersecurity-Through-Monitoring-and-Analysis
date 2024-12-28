import pickle
import pandas as pd
from sklearn.ensemble import IsolationForest

# Load the trained model
model_path = "C:/Users/Uday Alugolu/OneDrive/Desktop/KeyloggerSoftware/models/anomaly_model.pkl"
try:
    with open(model_path, "rb") as file:
        model = pickle.load(file)
except FileNotFoundError:
    print(f"Error: Model file not found at {model_path}")
    exit()

# Load the data
data_path = "C:/Users/Uday Alugolu/OneDrive/Desktop/KeyloggerSoftware/data/keystroke_data.csv"
try:
    data = pd.read_csv(data_path)
except FileNotFoundError:
    print(f"Error: Data file not found at {data_path}")
    exit()

# Display the first few rows of the data for verification
print("Data loaded successfully:")
print(data.head())

# Ensure the columns are correctly named and present
if 'typing_speed' not in data.columns or 'key_interval' not in data.columns:
    print("Error: Required columns ('typing_speed', 'key_interval') not found in the data.")
    exit()

# Use the correct features for predictions
features = ['typing_speed', 'key_interval']
X = data[features]

# Predict anomalies using the loaded model
predictions = model.predict(X)

# Print predictions to check
print("Predictions for the baseline data (1: normal, -1: anomaly):")
print(predictions)

# Check if any anomalies are detected (predicted as -1)
if all(predictions != -1):
    print("Anomaly detection tests passed.")
else:
    print("Anomaly detected in baseline data.")

# Optionally, you can also print the number of anomalies detected
num_anomalies = sum(predictions == -1)
print(f"Number of anomalies detected: {num_anomalies}")
