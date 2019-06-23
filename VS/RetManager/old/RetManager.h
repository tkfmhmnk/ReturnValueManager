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

#ifndef _RET_MANAGER_H
#define _RET_MANAGER_H

class Ret {
public:
	/**
		戻り値のフラグの意味を定義する列挙型。valの各フラグと対応する。
	*/
	enum _Ret : unsigned char {
		OK = 0,
		NG,
	};

	/**
		コンストラクタ
	*/
	Ret();

	/**
		複数の_Retによってvalを初期化するコンストラクタ
	*/
	template<class... Args> constexpr Ret(const Args... args) : val(calVal(args...)) {
	};

	unsigned int GetData();

	/**
		retのフラグをセットする
	*/
	Ret& Set(const _Ret ret);

	/**
		retのフラグをクリアする
	*/
	Ret& Clear(const _Ret ret);


	/**
		全てフラグをクリアする
	*/
	Ret& ClearAll();

	/**
		retのフラグがセットされているか確認する
	*/
	bool IsSet(const _Ret ret) const;

	/**
		retのフラグがクリアされているか確認する
	*/
	bool IsCleared(const _Ret ret) const;

	/**
		retのフラグ以外をマスクする
	*/
	Ret& Mask(const _Ret ret);


	/*---代入演算子---*/
	/**
		retのビットのみがセットされた状態にする
	*/
	Ret& operator =(const _Ret ret);

	/**
		retのフラグをセットする
	*/
	Ret& operator +=(const _Ret ret);

	/**
		retのフラグをクリアする
	*/
	Ret& operator -=(const _Ret ret);

	/**
		retのフラグをセットする
	*/
	Ret& operator |=(const _Ret ret);

	/**
		retのフラグ以外をマスクする
	*/
	Ret& operator &=(const _Ret ret);

	/**
		retのフラグをセットする
	*/
	Ret& operator <<(const _Ret ret);


	/*---算術演算子---*/
	/**
		retのフラグをセットする
	*/
	Ret operator +(const _Ret ret) const;

	/**
		retのフラグをクリアする
	*/
	Ret operator -(const _Ret ret) const;

	/**
		retのフラグをセットする
	*/
	Ret operator |(const _Ret ret) const;

	/**
		retのフラグ以外をマスクする
	*/
	Ret operator &(const _Ret ret) const;


	/*---比較演算子---*/
	/**
		retのフラグのみがセットされているか確認する
	*/
	bool operator ==(const _Ret ret) const;

	/**
		retのフラグのみがセットされていないか確認する
	*/
	bool operator !=(const _Ret ret) const;

	/**
		retのフラグ未満のフラグのみがセットされているか確認する
	*/
	bool operator <(const _Ret ret) const;

	/**
		retのフラグ以下のフラグのみがセットされているか確認する
	*/
	bool operator <=(const _Ret ret) const;

	/**
		retのフラグを超えるフラグがセットされているか確認する
	*/
	bool operator >(const _Ret ret) const;

	/**
		retのフラグ以上のフラグがセットされているか確認する
	*/
	bool operator >=(const _Ret ret) const;


	/*---Ret同士の比較演算子---*/
	/**
		valが等しいか確認する
	*/
	bool operator ==(const Ret& rhs) const;

	/**
		valが異なるか確認する
	*/
	bool operator !=(const Ret& rhs) const;

	/**
		valの大きさを比較する
	*/
	bool operator <(const Ret& rhs) const;

	/**
		valの大きさを比較する
	*/
	bool operator <=(const Ret& rhs) const;

	/**
		valの大きさを比較する
	*/
	bool operator >(const Ret& rhs) const;

	/**
		valの大きさを比較する
	*/
	bool operator >=(const Ret& rhs) const;

private:
	/**
		_Retと対応するフラグデータ
	*/
	unsigned int val;

	/**
		複数の_Retからvalの値を計算する
	*/
	template<class... Args> static constexpr unsigned char calVal(const _Ret ret, const Args... args) {
		return calVal(args...) | 1u << (unsigned char)ret;
	};

	/**
		calValの再帰終了のための関数
	*/
	static constexpr unsigned char calVal() {
		return 0;
	}
};

#endif