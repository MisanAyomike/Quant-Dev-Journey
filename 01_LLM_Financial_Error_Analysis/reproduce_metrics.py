import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# Define the precise column array from my UChicago paper
columns = [
    "Total Revenue/Net Sales",
    "Operating Profits",
    "Basic Earnings Per Share (EPS)",
    "Research and Development (R&D)",
    "Total Employees",
    "Operating Margin",
]

# Block A: My exact Manual Human Review dataset matrix (Table 1)
manual_dataset = {
    "ASTAZENECA": [45811.0, 8193.0, 3.84, 10935.0, 89900.0, 0.1790],
    "BRISTOL MYERS SQUIBB": [45006.0, 8440.0, 3.86, 9299.0, 30000.0, 0.1875],
    "HOFFMANN-LA ROCHE (CHF)": [58716.0, 19240.0, 9.60, 13237.0, 103605.0, 0.3277],
    "PFIZER": [58496.0, 1058.0, 0.38, 10679.0, 88000.0, 0.0180],
    "TAKEDA PHARMS (yen)": [
        4263800.0,
        214100.0,
        92.00,
        774391.2,
        50000.0,
        0.0500,
    ],
    "EMD SERONO INC (euro)": [20993.0, 3609.0, 6.49, 2445.0, 62908.0, 0.1720],
    "NOVARTIS PHARM": [45440.0, 9769.0, 7.15, 11371.0, 76057.0, 0.2150],
    "BLUEPRINT MEDICINES": [249.38, -507.0, 1.00, 427.72, 655.0, -2.0330],
    "ELI LILLY AND COMPANY": [34124.1, 6554.6, 5.82, 9313.4, 43000.0, 0.1920],
    "MODERNA INC": [6848.0, -4239.0, -12.33, 4845.0, 5600.0, -0.6190],
    "GSK (pounds)": [30328.0, 6745.0, 1.216, 6223.0, 70212.0, 0.2220],
    "AMGEN": [28190.0, 7897.0, 12.56, 4784.0, 26700.0, 0.2801],
    "MILLENNIUM": [265.76, 2.687, 0.0129, 1.0, 4887.0, 0.0101],
    "EXELIXIS INC": [1830.208, 170.885, 0.65, 1044.071, 1310.0, 0.0934],
    "ONYX HEALTHCARE": [1492.86, 211.254, 7.65, 79.362, 153.0, 0.1415],
    "REGENERON PHARMAS": [13117.2, 4047.1, 37.05, 4439.0, 13450.0, 0.3085],
    "DAIICHI SANKYO (yen)": [
        1278478.0,
        120580.0,
        56.96,
        341570.0,
        17435.0,
        0.0943,
    ],
    "BAYER (euro)": [47637.0, 612.0, -2.99, 5371.0, 99723.0, 0.0128],
    "BIOMARIN": [2419.226, -158.097, -0.89, 746.8, 3401.0, -0.0654],
    "EISAI (yen)": [741800.0, 53400.0, 147.90, 16900.0, 1.0, 0.0720],
}

# Block B: My exact GPT-4o Model Extraction dataset matrix (Table 2)
gpt4o_dataset = {
    "ASTAZENECA": [45811.0, 8193.0, 3.84, 10935.0, 89900.0, 0.1790],
    "BRISTOL MYERS SQUIBB": [45000.0, 0.0, 3.86, 9300.0, 30000.0, 0.0000],
    "HOFFMANN-LA ROCHE (CHF)": [58716.0, 19240.0, 9.60, 13237.0, 103605.0, 0.3276],
    "PFIZER": [58496.0, 1058.0, 0.38, 11407.0, 83000.0, 0.0180],
    "TAKEDA PHARMS (yen)": [4263800.0, 214100.0, 92.00, 0.0, 0.0, 0.0500],
    "EMD SERONO INC (euro)": [20993.0, 3609.0, 6.49, 2400.0, 62908.0, 0.1720],
    "NOVARTIS PHARM": [45440.0, 9769.0, 7.15, 11371.0, 76057.0, 0.2150],
    "BLUEPRINT MEDICINES": [249.4, -506.0, 1.00, 427.7, 655.0, -2.0290],
    "ELI LILLY AND COMPANY": [34124.1, 6554.6, 5.82, 9313.4, 43000.0, 0.1920],
    "MODERNA INC": [6848.0, -4239.0, -12.33, 4845.0, 5600.0, -0.6189],
    "GSK (pounds)": [30300.0, 6745.0, 1.216, 5562.0, 70212.0, 0.2220],
    "AMGEN": [28190.0, 7897.0, 12.56, 4784.0, 0.0, 0.2930],
    "MILLENNIUM": [265.76, 0.95, 0.0129, 1.0, 4887.0, 0.0036],
    "EXELIXIS INC": [1830.2, 170.9, 0.65, 1044.1, 1310.0, 0.0934],
    "ONYX HEALTHCARE": [1492.86, 255.17, 7.65, 79.36, 153.0, 0.1710],
    "REGENERON PHARMAS": [13117.2, 4047.1, 37.05, 4439.0, 13450.0, 0.3085],
    "DAIICHI SANKYO (yen)": [
        1278500.0,
        120600.0,
        56.96,
        341600.0,
        17435.0,
        0.0940,
    ],
    "BAYER (euro)": [49253.0, 612.0, -2.99, 5371.0, 99723.0, 0.0124],
    "BIOMARIN": [2419.2, 230.1, 0.89, 832.5, 3401.0, 0.0950],
    "EISAI (yen)": [741800.0, 53400.0, 152.5, 16750.0, 1.0, 0.0720],
}

# Transform dictionaries into structured DataFrames
df_manual = pd.DataFrame.from_dict(manual_dataset, orient="index", columns=columns)
df_ai = pd.DataFrame.from_dict(gpt4o_dataset, orient="index", columns=columns)

# Replicate directional error calculations from my paper
# Formula handles zero cases robustly using standard programmatic variations
df_directional_error = pd.DataFrame(np.zeros(df_manual.shape), index=df_manual.index, columns=columns)
for col in columns:
    for row in df_manual.index:
        m_val = df_manual.at[row, col]
        a_val = df_ai.at[row, col]
        if a_val == 0 and m_val == 0:
            df_directional_error.at[row, col] = 0.0
        elif a_val == 0:
            df_directional_error.at[row, col] = -1.0 if m_val > 0 else 1.0
        else:
            df_directional_error.at[row, col] = (m_val - a_val) / a_val

# Calculate absolute errors (Translating Excel's =ABS() matrix)
df_absolute_error = df_directional_error.abs()


def display_verification_report():
    print("====================================================")
    print("      BARUCH MFE APPLICATION DATA VERIFICATION       ")
    print("====================================================\n")
    
    print("--- GLOBAL ERROR METRICS (FULL SAMPLE) ---")
    print(f"Directional Mean Error   : {df_directional_error.values.mean() * 100:.6f}% (Paper Target: -10.597833%)")
    print(f"Absolute Mean Error      : {df_absolute_error.values.mean() * 100:.6f}% (Paper Target: 11.782741%)")
    print(f"Absolute Standard Dev    : {df_absolute_error.values.std() * 100:.6f}% (Paper Target: 41.338059%)\n")
    
    print("--- REPRODUCED CATEGORICAL METRIC MATRIX ---")
    categorical_breakdown = pd.DataFrame({
        "Abs Mean (%)": df_absolute_error.mean() * 100,
        "Abs StDev (%)": df_absolute_error.std() * 100,
        "Dir Mean (%)": df_directional_error.mean() * 100,
        "Dir StDev (%)": df_directional_error.std() * 100
    })
    print(categorical_breakdown.round(4).to_string())
    print("\n====================================================")
    
    # --- AUTOMATED CHART GENERATION MODULE ---
    print("\n[System] Generating Standard Deviation Metrics Visualizations...")
    
    # Establish graph canvas size and style
    plt.figure(figsize=(11, 6))
    
    # Target my specific Absolute Standard Deviation metrics array
    metrics_labels = [col.replace('/', '\n') for col in columns] # Clean up labels for display
    stdev_values = df_absolute_error.std() * 100
    
    # Draw my professional green bar charts matching my paper's aesthetic
    bars = plt.bar(metrics_labels, stdev_values, color='#1E5631', edgecolor='black', width=0.5)
    
    # Add numerical value callouts directly on top of each bar structure
    for bar in bars:
        yval = bar.get_height()
        plt.text(bar.get_x() + bar.get_width()/2.0, yval + 1.5, f"{yval:.2f}%", ha='center', va='bottom', fontsize=10, weight='bold')
    
    # Add professional headers and boundary limits
    plt.title('Absolute Standard Deviation of Error (%) per Financial Metric Array', fontsize=13, weight='bold', pad=15)
    plt.ylabel('Standard Deviation of Error (%)', fontsize=11, weight='bold')
    plt.ylim(0, 70)
    plt.grid(axis='y', linestyle='--', alpha=0.5)
    
    # Save the output visualization directly to the repository folder
    plt.tight_layout()
    plt.savefig('01_LLM_Financial_Error_Analysis/absolute_stdev_error_chart.png', dpi=300)
    print("[System] Success! Chart exported as 'absolute_stdev_error_chart.png'.")

if __name__ == "__main__":
    display_verification_report()


