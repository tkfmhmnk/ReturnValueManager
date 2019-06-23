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

#include"Ret_base.h"

class ModuleRet {
public:
	/**
		戻り値のフラグの意味を定義する列挙型。valの各フラグと対応する。
	*/
	enum _Ret : unsigned char {
		OK = 0,
		NG
	};


};

typedef Ret_base<ModuleRet> Ret;

Ret func() {
	Ret ret = Ret::OK;
	Ret ret2;
	ret2 = Ret::OK;

	return ret;
}

int main() {
	static constexpr Ret A(Ret::OK, Ret::NG);
	Ret B(Ret::OK, Ret::NG);
	if (A == Ret::OK) {

	}
	if (A == (Ret() | Ret::OK | Ret::NG)) {

	}

	if (A == (Ret() << Ret::OK << Ret::NG)) {

	}
	if (A == B) {

	}

	Ret ret;
	ret = func();

	if ((ret & Ret::OK) == Ret::OK) {
		int a;
	}

	if (ret.IsSet(Ret::OK)) {

	}
	ret.Set(ModuleRet::OK);
	return 0;
}

