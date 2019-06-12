/*!
 * \file cubature_filter.h
 * \brief Interface of a library with Bayesian noise statistic estimation
 *
 * Cubature_Filter implements the functionality of the Cubature Kalman
 * Filter, which uses multidimensional cubature rules to estimate the
 * time evolution of a nonlinear system.
 *
 * [1] I Arasaratnam and S Haykin. Cubature kalman filters. IEEE 
 * Transactions on Automatic Control, 54(6):1254–1269,2009.
 *
 * \authors <ul>
 *          <li> Gerald LaMountain, 2019. gerald(at)ece.neu.edu
 *          <li> Jordi Vila-Valls 2019. jvila(at)cttc.es
 *          </ul>
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_CUBATURE_FILTER_H_
#define GNSS_SDR_CUBATURE_FILTER_H_

#include <armadillo>
#include <gnuradio/gr_complex.h>

// Abstract model function
class ModelFunction{
    public:
        ModelFunction() {};
        virtual arma::vec operator() (arma::vec input) = 0;
        virtual ~ModelFunction() = default;
};

class TestModel{
    public:
        TestModel() {};
        //virtual arma::vec operator() (arma::vec input) = 0;
        virtual double operator() (double input) = 0;
        virtual ~TestModel() = default;
};

class Cubature_filter
{
public:
    // Constructors and destructors
    Cubature_filter();
    Cubature_filter(int nx);
    Cubature_filter(const arma::vec& x_pred_0, const arma::mat& P_x_pred_0);
    ~Cubature_filter();

    // Reinitialization function
    void initialize(const arma::mat& x_pred_0, const arma::mat& P_x_pred_0);

    // Prediction and estimation
    void predict_sequential(const arma::vec& x_post, const arma::mat& P_x_post, ModelFunction* transition_fcn, const arma::mat& noise_covariance);
    void update_sequential(const arma::vec& z_upd, const arma::vec& x_pred, const arma::mat& P_x_pred, ModelFunction* measurement_fcn, const arma::mat& noise_covariance);

    // Getters
    arma::mat get_x_pred() const;
    arma::mat get_P_x_pred() const;
    arma::mat get_x_est() const;
    arma::mat get_P_x_est() const;

    //Test-dev
    double func_number(double number, TestModel* func);

private:
    arma::vec x_pred_out;
    arma::mat P_x_pred_out;
    arma::vec x_est;
    arma::mat P_x_est;
};

#endif
