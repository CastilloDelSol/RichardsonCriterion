/**
 * @brief RichardsonCriterion class implements the Richardson Extrapolation convergence criterion.
 * 
 * The RichardsonCriterion class provides a mechanism to determine whether a sequence of data points
 * has converged using Richardson Extrapolation technique. This technique is commonly used in numerical
 * analysis to estimate the limit of a sequence by extrapolating values from nearby points in the sequence.
 * 
 * The class maintains an array of the last three data points added and checks for convergence based on
 * the difference between the extrapolated solution and the last data point. When the difference falls
 * below a specified epsilon threshold, it indicates convergence.
 */
template<typename T>
class RichardsonCriterion {
private:
    T x[3];       /**< Array to store the last three data points */
    uint8_t pos;  /**< Position index for adding new data points */
    T epsilon;    /**< Convergence threshold */

public:
    /**
     * @brief Constructor for RichardsonCriterion class.
     *
     * @param epsilon The convergence threshold.
     */
    RichardsonCriterion(T eps) : pos(0), epsilon(eps) {}

    /**
     * @brief Add a new data point to the sequence.
     *
     * @param point The new data point to be added.
     *
     * This function adds a new data point to the sequence, updating the internal array
     * of the last three data points. If the array is full, it shifts the elements to
     * make space for the new data point.
     */
    void addDataPoint(T point)
    {
        if (pos >= 3)
        {
            // If the array is full, shift elements to make space for the new data point
            x[0] = x[1];
            x[1] = x[2];
            pos--; // Decrement position index
        }

        x[pos++] = point; // Add the new data point at the current position
    }

    /**
     * @brief Check for convergence based on Richardson Extrapolation.
     *
     * @return True if convergence is achieved, False otherwise.
     *
     * This function calculates the Richardson Extrapolation prediction based on the
     * last three data points and checks if the difference between the prediction and
     * the last data point is below the specified epsilon threshold. If so, it indicates
     * convergence and resets the internal state.
     */
    bool hasConverged()
    {
        if (pos < 3)
        {
            // Not enough data points to check convergence
            return false;
        }

        T h = x[1] - x[0];
        T q = (x[2] - x[1]) / h;

        T prediction = x[2] + q * (x[2] - x[1] + h) / (1.0 - q);

        if (abs(x[2] - prediction) < epsilon)
        {
            return true;
        }

        return false;
    }

    /**
    * @brief Reset the internal state of the RichardsonCriterion instance.
    *
    * This function resets the position index for adding new data points
    * back to the initial state, effectively clearing the sequence of data
    * points stored in the object. It is useful for reinitializing the
    * convergence check process, ensuring that the convergence check starts
    * afresh with a clean slate, considering only the newly added data points.
    */
    void reset()
    {
        pos = 0;
    }
};
