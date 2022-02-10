/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem
{
public:
    ParkingSystem(int big, int medium, int small) : big_(big), medium_(medium), small_(small) {}

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (big_)
            {
                --big_;
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 2:
            if (medium_)
            {
                --medium_;
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 3:
            if (small_)
            {
                --small_;
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            break;
        }
        
        return false;
    }

private:
    int big_;
    int medium_;
    int small_;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
