# Evaluating the Efficiency and Accuracy of GPT-4o in Financial Data Extraction

## Project Components & Research Assets
This repository represents the comprehensive data science and research portfolio compiled during my quantitative research internship at the **University of Chicago**. To explore the academic, operational, and code assets of this study, please refer to the following directory structure:

* **`Evaluating Efficiency and Accuracy GPT4o.pdf`** — The complete, unpublished coauthored research paper detailing our core empirical methodology, error baselines, and data sample boundaries.
* **`Symposium Presentation Deck.pptx`** — The visual deck developed and utilized to present our findings at the Leadership Alliance academic research symposium.
* **`data/"Data analysis_for pharmaceutical annual reports".xlsx`** — The original master Microsoft Excel workbook containing our raw data entry fields, pivot summaries, and validation formulas.
* **`data/manual_review.csv`** — Clean tabular export of the 120 baseline data points compiled over our 8.5-hour audited manual human review.
* **`data/gpt4o_extract.csv`** — Clean tabular export of the 120 parameters extracted by the Large Language Model in 1.5 hours.
* **`reproduce_metrics.py`** — The production-ready Python automation script built to verify and display our statistical breakdowns(it also produces the absolute_stdev_error_chart).

##  Project Overview
Under the guidance of Principal Investigator **Dr. Pietro Veronesi** at the University of Chicago Booth School of Business, this study evaluated **GPT-4o’s extraction efficiency and structural accuracy** against an audited manual human baseline. 

The study tracked 6 critical financial parameters across the 2023 annual reports of 20 pharmaceutical companies involved in oncology research (240 total observations):
* Total Revenue / Net Sales
* Operating Profits / Loss
* Basic Earnings Per Share (EPS)
* Research and Development (R&D) Expenditures
* Total Employee Scale
* Operating Margin Percentage

## Key Analytical Takeaways
* **The Speed Advantage:** GPT-4o processed the entire corporate annual report array in **1 hour and 30 minutes**, compared to **8 hours and 30 minutes** for the manual human baseline—yielding an efficiency gain ratio of **5.86x**.
* **Global Error Rates:** Disregarding directional discrepancies, GPT-4o demonstrated **86% absolute accuracy** within a strict 5% error baseline.
* **Underestimation Vectors:** The model showed a consistent structural tendency to underestimate complex operational values, maintaining a negative directional average error of **-10.60%**. However, it achieved perfect convergence (**0.00% error**) at the median for over half of the total observations.

## 🛠️ Portfolio Migration & Mathematical Alignment
The core data parsing, financial parameters, and statistical logic of this study were originally executed using Microsoft Excel. 

To optimize this project for a modern quantitative development workflow, I ported the original mathematical frameworks into a pythonic automation script (`reproduce_metrics.py`) using `pandas`, `numpy`, and `matplotlib`.

### Mathematical Convergence Note
During the initial porting phase, tracking discrepancies were isolated and resolved by aligning the script's calculation parameters with the exact percentage error logic implemented in the UChicago Excel spreadsheet. While standard variations check error relative to the AI's estimation, true mathematical convergence down to the sixth decimal point was achieved by evaluating directional error relative to our **audited human baseline**:

$$\text{Error} = \frac{\text{AI Extracted Value} - \text{Manual Human Baseline}}{\text{Manual Human Baseline}}$$

Enforcing this equation across our data arrays guarantees 100% data fidelity, confirming our absolute mean error at **11.7827%** and full-sample standard deviation at **41.3381%**, completely mirroring our verified academic results.

### Validated Statistical Breakdown (Reproduced via Python)

| Financial Metric | Absolute Mean Error (%) | Absolute Standard Deviation (%) | Directional Mean Error (%) | Directional Standard Deviation (%) |
| :--- | :--- | :--- | :--- | :--- |
| **Total Revenue / Net Sales** | 0.1755% | 0.7574% | 0.1647% | 0.7600% |
| **Operating Profits** | 21.5599% | 58.7618% | -19.4786% | 59.5220% |
| **Basic Earnings Per Share (EPS)** | 10.1555% | 44.6902% | -9.8445% | 44.7634% |
| **Research & Development (R&D)** | 6.5836% | 22.2761% | -4.7521% | 22.7614% |
| **Total Employees** | 10.2841% | 30.7083% | -10.2841% | 30.7083% |
| **Operating Margin** | 21.9378% | 58.5503% | -19.3925% | 59.4884% |

##  Execution Instructions
To activate your environment and execute the automated metrics verification script:
```bash
# Clone the repository
git clone https://github.com/misanayomike/quant-dev-journey.git

# Navigate to the project folder
cd quant-dev-journey/01_LLM_Financial_Error_Analysis

# Run the metrics reproduction script
python reproduce_metrics.py
```
