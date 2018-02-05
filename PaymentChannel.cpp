/*
 * PaymentChannel.cpp
 *
 *  Created on: 06 lug 2016
 *      Author: giovanni
 */

#include "PaymentChannel.h"
#include "LightningNetwork.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include "defs.h"

PaymentChannel::PaymentChannel(PaymentChannelEndPoint * A,
		PaymentChannelEndPoint * B, ln_units resFundsA, ln_units resFundsB) {
	this->A=A;
	this->B=B;
	this->residualFundsA=resFundsA;
	this->residualFundsB=resFundsB;
}

PaymentChannel::~PaymentChannel() {
	// TODO Auto-generated destructor stub
}

void PaymentChannel::PayA(double Payment) {
	long int units=Payment/MINIMUM_UNIT;

	double P=((double)units)*MINIMUM_UNIT;

	std::cout << "Res B" << residualFundsB << " Payment " << P << "\n";

	assert( residualFundsB-P>-MINIMUM_UNIT );
	this->residualFundsB-=P;

	std::cout << std::setprecision(15) << "paying " << P << "\n";

	this->residualFundsA+=P;
}

void PaymentChannel::PayB(double payment) {

	long int units=payment/MINIMUM_UNIT;
	double P=((double)units)*MINIMUM_UNIT;

	assert(residualFundsA-P>-MINIMUM_UNIT);
	this->residualFundsA-=P;
	this->residualFundsB+=P;
}


void PaymentChannelGeneralFees::addSlopeA(long start, double coeff){
  coefficientsA.push_back(coeff);
  starting_pointsA.push_back(start);
}

void PaymentChannelGeneralFees::addSlopeB(long start, double coeff){
  coefficientsB.push_back(coeff);
  starting_pointsB.push_back(start);
}



