# 🚗 RL-Model-Car
A reinforcement learning (Q-learning) and imitation learning (behavior cloning) project to control a small model car. The car learns to navigate using either **trial-and-error (Q-learning)** or **expert demonstrations (imitation learning).**

---

## 📌 Features
- **Q-learning**: The car learns by trial and error using a **Q-table**.
- **Imitation Learning**: The car mimics expert driving behavior using **supervised learning**.
- **Simulated & Real-world Deployment**: Supports testing in a **simulated environment** and **real-world deployment** (e.g., Raspberry Pi).
- **Sensor-based Control**: Uses sensor data (e.g., ultrasonic sensors) to make decisions.



RL-Model-Car/
│── data/                     # Stores training datasets
│   ├── expert_data.csv        # Collected expert demonstrations
│   ├── logs/                  # Logs for training performance
│
│── models/                    # Stores trained models
│   ├── q_table.npy            # Saved Q-table (for Q-learning)
│   ├── imitation_model.pkl    # Trained Imitation Learning model
│
│── src/                       # Core source code
│   ├── q_learning.py          # Q-learning implementation
│   ├── imitation_learning.py  # Imitation learning (Behavior Cloning)
│   ├── train_q_learning.py    # Training script for Q-learning
│   ├── train_imitation.py     # Training script for imitation learning
│   ├── collect_data.py        # Collects expert data (for imitation learning)
│   ├── real_car_control.py    # Interface for real-world model car control
│
│── notebooks/                 # Jupyter notebooks for analysis
│   ├── Q_Learning_Training.ipynb  # Training and debugging Q-learning
│   ├── Imitation_Learning.ipynb   # Training and testing imitation model
│
│── tests/                     # Unit and integration tests
│   ├── test_q_learning.py      # Tests for Q-learning functions
│   ├── test_imitation.py       # Tests for imitation learning functions
│
│── utils/                     # Utility functions
│   ├── env_simulation.py       # Simulated environment for testing
│   ├── preprocess.py           # Data preprocessing functions
│
│── deployment/                 # Deployment scripts for real-world testing
│   ├── run_on_raspberry_pi.py  # Script to run on a Raspberry Pi
│   ├── deploy_model.py         # Loads trained model and runs it on hardware
│
│── requirements.txt            # Required Python packages
│── README.md                   # Overview of the project
│── .gitignore                   # Ignore unnecessary files (logs, models, etc.)
