/*
Copyright 2019 tkfmhmnk

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissionsand
limitations under the License.
*/

#include "RetManager.h"

Ret::Ret() : val(0) {

};

unsigned int Ret::GetData() {
	return val;
};


Ret& Ret::Set(const _Ret ret) {
	val |= 1u << (unsigned char)ret;
	return *this;
};

Ret& Ret::Clear(const _Ret ret) {
	val &= ~(1u << (unsigned char)ret);
	return *this;
};


Ret& Ret::ClearAll() {
	val = 0;
	return *this;
};

bool Ret::IsSet(const _Ret ret) const {
	if ((val & (1u << (unsigned char)ret)) == 0) {
		return false;
	}
	else {
		return true;
	}
};

bool Ret::IsCleared(const _Ret ret) const {
	return !IsSet(ret);
};

Ret& Ret::Mask(const _Ret ret) {
	val &= 1u << (unsigned char)ret;
	return *this;
};


/*---‘ã“ü‰‰ŽZŽq---*/

Ret& Ret::operator =(const _Ret ret) {
	val = 1u << (unsigned char)ret;
	return *this;
};

Ret& Ret::operator +=(const _Ret ret) {
	return Set(ret);
};

Ret& Ret::operator -=(const _Ret ret) {
	return Clear(ret);
};

Ret& Ret::operator |=(const _Ret ret) {
	return Set(ret);
};

Ret& Ret::operator &=(const _Ret ret) {
	return Mask(ret);
};

Ret& Ret::operator <<(const _Ret ret) {
	return Set(ret);
};


/*---ŽZp‰‰ŽZŽq---*/
Ret Ret::operator +(const _Ret ret) const {
	Ret temp = *this;
	return temp.Set(ret);
};

Ret Ret::operator -(const _Ret ret) const {
	Ret temp = *this;
	return temp.Clear(ret);
};

Ret Ret::operator |(const _Ret ret) const {
	Ret temp = *this;
	return temp.Set(ret);
};

Ret Ret::operator &(const _Ret ret) const {
	Ret temp = *this;
	return temp.Mask(ret);
};


/*---”äŠr‰‰ŽZŽq---*/
bool Ret::operator ==(const _Ret ret) const {
	if (val == 1u << (unsigned char)ret) return true;
	else return false;
};

bool Ret::operator !=(const _Ret ret) const {
	if (val != 1u << (unsigned char)ret) return true;
	else return false;
};

bool Ret::operator <(const _Ret ret) const {
	if (val < (1u << (unsigned char)ret)) {
		return true;
	}
	else {
		return false;
	}
};

bool Ret::operator <=(const _Ret ret) const {
	if (val < (1u << ((unsigned char)ret + 1))) {
		return true;
	}
	else {
		return false;
	}
};

bool Ret::operator >(const _Ret ret) const {
	return !operator<=(ret);
};

bool Ret::operator >=(const _Ret ret) const {
	return !operator<(ret);
};


/*---Ret“¯Žm‚Ì”äŠr‰‰ŽZŽq---*/
bool Ret::operator ==(const Ret& rhs) const {
	if (val == rhs.val) return true;
	else return false;
};

bool Ret::operator !=(const Ret& rhs) const {
	if (val != rhs.val) return true;
	else return false;
};

bool Ret::operator <(const Ret& rhs) const {
	if (val < rhs.val) return true;
	else return false;
};

bool Ret::operator <=(const Ret& rhs) const {
	if (val <= rhs.val) return true;
	else return false;
};

bool Ret::operator >(const Ret& rhs) const {
	if (val > rhs.val) return true;
	else return false;
};

bool Ret::operator >=(const Ret& rhs) const {
	if (val >= rhs.val) return true;
	else return false;
};