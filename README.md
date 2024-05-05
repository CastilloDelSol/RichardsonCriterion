RichardsonCriterion Class Documentation
================================================================================

Author: Jon Doe
Date Created: May 3, 2024
Date Last Updated: N/A

Overview:
================================================================================

The RichardsonCriterion class implements the Richardson Extrapolation convergence
criterion. This technique is commonly used in numerical analysis to estimate the
limit of a sequence by extrapolating values from nearby points in the sequence.

Class Information:
================================================================================

Class Name: RichardsonCriterion
Version: 1.00
Author: Jon Doe
Date Created: May 3, 2024
Date Last Updated: N/A

Description:
================================================================================

The RichardsonCriterion class provides a mechanism to determine whether a sequence
of data points has converged using Richardson Extrapolation technique. This class
offers improved accuracy and adaptability compared to a simple epsilon check, 
making it suitable for various numerical analysis applications.

Benefits Compared to Simple Epsilon Check:
================================================================================

1. Extrapolation Technique: The Richardson extrapolation technique used in the class provides a more sophisticated approach to estimating convergence. It takes into account the relationship between successive data points to predict convergence more accurately, especially in cases where the convergence behavior is complex or non-linear.

2. Automatic Handling of Data: The class automatically maintains a history of the last three data points and performs the necessary calculations for Richardson extrapolation. This eliminates the need for manual tracking of data points and simplifies the convergence check process.

3. Improved Accuracy: By considering the trend of data points, the Richardson extrapolation technique can lead to more accurate convergence detection, especially in scenarios where the convergence rate varies or is unknown. This can result in fewer false positives or negatives compared to a simple epsilon check.

4. Adaptability: The class allows for easy adjustment of the convergence threshold (epsilon) and can adapt to different convergence criteria or precision requirements without modifying the convergence check logic.

5. Reusability and Maintainability: Once implemented, the RichardsonCriterion class can be reused across multiple applications or scenarios without the need for significant modifications. It encapsulates the convergence check logic, making it easier to maintain and debug.

Usage Examples:
================================================================================

/examples/step_response/step_response.ino

Dependencies:
================================================================================

None

Known Issues or Limitations:
================================================================================

None


