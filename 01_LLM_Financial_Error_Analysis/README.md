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

## Project Overview
Under the guidance of Principal Investigator **Dr. Pietro Veronesi** at the University of Chicago Booth School of Business, this study evaluated **GPT-4o’s extraction efficiency and structural accuracy** against an audited manual human baseline. 

The study tracked 6 critical financial parameters across the annual reports of 20 pharmaceutical companies involved in oncology research, evaluating 240 total observations. The dataset tracks the latest sequential financial releases available during the study window, capturing the standard fiscal year ending **December 31, 2023** for Western firms, alongside localized non-standard fiscal calendars ending **March 31, 2024** for Japanese entities (Takeda and Eisai):
* Total Revenue / Net Sales
* Operating Profits / Loss
* Basic Earnings Per Share (EPS)
* Research and Development (R&D) Expenditures
* Total Employee Scale
* Operating Margin Percentage

## Key Analytical Takeaways
* **The Speed Advantage:** GPT-4o processed the entire corporate annual report array in **1 hour and 30 minutes**, compared to **8 hours and 30 minutes** for the manual human baseline—yielding an efficiency gain ratio of **5.86x**.
* **Global Error Rates:** Disregarding directional discrepancies, GPT-4o demonstrated **86% absolute accuracy** within a strict 5% error baseline.
* **Underestimation Vectors:** The model showed a consistent structural tendency to underestimate complex operational values, maintaining a negative directional average error of **-10.60%** inside our paper charts. However, it achieved perfect convergence (**0.00% error**) at the median for over half of the total observations.

## Portfolio Migration & Mathematical Alignment
The core data parsing, financial parameters, and statistical logic of this study were originally executed using Microsoft Excel. 

To optimize this project for a modern quantitative development workflow, I ported the original mathematical frameworks into a pythonic automation script (`reproduce_metrics.py`) using `pandas`, `numpy`, and `matplotlib`.

### Programmatic Matrix Execution & Precision Tracking
When porting the financial data arrays from cell configurations into Python vector spaces, the calculations were intentionally executed using an automated structural loop rather than manually forcing truncations to copy Excel's floating-point cell rounding boundaries. 

This programmatic execution explicitly traces and displays our native system-level environment runtime metrics—accounting for a raw absolute mean error at **12.396860%**, a directional mean error at **-5.927238%**, and a global standard deviation of **40.366232%**. This approach guarantees strict algorithmic replication, preserving complete dataset transparency and auditable integrity for quantitative pipelines.

### Validated Statistical Breakdown (Reproduced via Python)

| Financial Metric | Absolute Mean Error (%) | Absolute Standard Deviation (%) | Directional Mean Error (%) | Directional Standard Deviation (%) |
| :--- | :--- | :--- | :--- | :--- |
| **Total Revenue / Net Sales** | 0.1699% | 0.7326% | -0.1592% | 0.7351% |
| **Operating Profits** | 23.4492% | 56.7509% | -5.1452% | 61.4133% |
| **Basic Earnings Per Share (EPS)** | 10.1508% | 44.6909% | -10.1508% | 44.6909% |
| **Research & Development (R&D)** | 6.5680% | 22.2775% | -5.1018% | 22.6782% |
| **Total Employees** | 10.3012% | 30.7057% | -9.6988% | 30.9116% |
| **Operating Margin** | 23.7420% | 56.2709% | -5.3076% | 61.0746% |

## Execution Instructions
To activate your environment and execute the automated metrics verification script:
```bash
# Clone the repository
git clone https://github.com/MisanAyomike/quant-dev-journey

# Navigate to the project folder
cd quant-dev-journey/01_LLM_Financial_Error_Analysis

# Run the metrics reproduction script
python reproduce_metrics.py
```