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

template<class ENUM_T>
class Ret_base : public ENUM_T{
public:
	/**
		コンストラクタ
	*/
	Ret_base() : val(0) {

	};

	/**
		複数の_Retによってvalを初期化するコンストラクタ
	*/
	template<class... Args> constexpr Ret_base(const Args... args) : val(calVal(args...)) {
	};

	/**
		valを取得する
	*/
	unsigned int GetData() {
		return val;
	};

	/**
		retのフラグをセットする
	*/
	Ret_base& Set(const typename ENUM_T::_Ret ret) {
		val |= 1u << (unsigned char)ret;
		return *this;
	};

	/**
		retのフラグをクリアする
	*/
	Ret_base& Clear(const typename ENUM_T::_Ret ret) {
		val &= ~(1u << (unsigned char)ret);
		return *this;
	};

	/**
		全てフラグをクリアする
	*/
	Ret_base& ClearAll() {
		val = 0;
		return *this;
	};

	/**
		retのフラグがセットされているか確認する
	*/
	bool IsSet(const typename ENUM_T::_Ret ret) const {
		if ((val & (1u << (unsigned char)ret)) == 0) {
			return false;
		}
		else {
			return true;
		}
	};

	/**
		retのフラグがクリアされているか確認する
	*/
	bool IsCleared(const typename ENUM_T::_Ret ret) const {
		return !IsSet(ret);
	};


	/**
		retのフラグ以外をマスクする
	*/
	Ret_base& Mask(const typename ENUM_T::_Ret ret) {
		val &= 1u << (unsigned char)ret;
		return *this;
	};


	/*---代入演算子---*/
	/**
		retのビットのみがセットされた状態にする
	*/
	Ret_base& operator =(const typename ENUM_T::_Ret ret) {
		val = 1u << (unsigned char)ret;
		return *this;
	};

	/**
		retのフラグをセットする
	*/
	Ret_base& operator +=(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};


	/**
		retのフラグをクリアする
	*/
	Ret_base& operator -=(const typename ENUM_T::_Ret ret) {
		return Clear(ret);
	};

	/**
		retのフラグをセットする
	*/
	Ret_base& operator |=(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};

	/**
		retのフラグ以外をマスクする
	*/
	Ret_base& operator &=(const typename ENUM_T::_Ret ret) {
		return Mask(ret);
	};

	/**
		retのフラグをセットする
	*/
	Ret_base& operator <<(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};


	/*---算術演算子---*/
	/**
		retのフラグをセットする
	*/
	Ret_base operator +(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Set(ret);
	};

	/**
		retのフラグをクリアする
	*/
	Ret_base operator -(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Clear(ret);
	};

	/**
		retのフラグをセットする
	*/
	Ret_base operator |(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Set(ret);
	};

	/**
		retのフラグ以外をマスクする
	*/
	Ret_base operator &(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Mask(ret);
	};


	/*---比較演算子---*/
	/**
		retのフラグのみがセットされているか確認する
	*/
	bool operator ==(const typename ENUM_T::_Ret ret) const {
		if (val == 1u << (unsigned char)ret) return true;
		else return false;
	};

	/**
		retのフラグのみがセットされていないか確認する
	*/
	bool operator !=(const typename ENUM_T::_Ret ret) const {
		if (val != 1u << (unsigned char)ret) return true;
		else return false;
	};

	/**
		retのフラグ未満のフラグのみがセットされているか確認する
	*/
	bool operator <(const typename ENUM_T::_Ret ret) const {
		if (val < (1u << (unsigned char)ret)) {
			return true;
		}
		else {
			return false;
		}
	};

	/**
		retのフラグ以下のフラグのみがセットされているか確認する
	*/
	bool operator <=(const typename ENUM_T::_Ret ret) const {
		if (val < (1u << ((unsigned char)ret + 1))) {
			return true;
		}
		else {
			return false;
		}
	};

	/**
		retのフラグを超えるフラグがセットされているか確認する
	*/
	bool operator >(const typename ENUM_T::_Ret ret) const {
		return !operator<=(ret);
	};

	/**
		retのフラグ以上のフラグがセットされているか確認する
	*/
	bool operator >=(const typename ENUM_T::_Ret ret) const {
		return !operator<(ret);
	};



	/*---Ret同士の比較演算子---*/
	/**
		valが等しいか確認する
	*/
	bool operator ==(const Ret_base& rhs) const {
		if (val == rhs.val) return true;
		else return false;
	};

	/**
		valが異なるか確認する
	*/
	bool operator !=(const Ret_base& rhs) const {
		if (val != rhs.val) return true;
		else return false;
	};

	/**
		valの大きさを比較する
	*/
	bool operator <(const Ret_base& rhs) const {
		if (val < rhs.val) return true;
		else return false;
	};

	/**
		valの大きさを比較する
	*/
	bool operator <=(const Ret_base& rhs) const {
		if (val <= rhs.val) return true;
		else return false;
	};

	/**
		valの大きさを比較する
	*/
	bool operator >(const Ret_base& rhs) const {
		if (val > rhs.val) return true;
		else return false;
	};

	/**
		valの大きさを比較する
	*/
	bool operator >=(const Ret_base& rhs) const {
		if (val >= rhs.val) return true;
		else return false;
	};

private:
	/**
		ENUM_T::_Retと対応するフラグデータ
	*/
	unsigned int val;

	/**
		複数のENUM_T::_Retからvalの値を計算する
	*/
	template<class... Args> static constexpr unsigned char calVal(const typename ENUM_T::_Ret ret, const Args... args) {
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