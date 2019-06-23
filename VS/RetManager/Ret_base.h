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
		�R���X�g���N�^
	*/
	Ret_base() : val(0) {

	};

	/**
		������_Ret�ɂ����val������������R���X�g���N�^
	*/
	template<class... Args> constexpr Ret_base(const Args... args) : val(calVal(args...)) {
	};

	/**
		val���擾����
	*/
	unsigned int GetData() {
		return val;
	};

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base& Set(const typename ENUM_T::_Ret ret) {
		val |= 1u << (unsigned char)ret;
		return *this;
	};

	/**
		ret�̃t���O���N���A����
	*/
	Ret_base& Clear(const typename ENUM_T::_Ret ret) {
		val &= ~(1u << (unsigned char)ret);
		return *this;
	};

	/**
		�S�ăt���O���N���A����
	*/
	Ret_base& ClearAll() {
		val = 0;
		return *this;
	};

	/**
		ret�̃t���O���Z�b�g����Ă��邩�m�F����
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
		ret�̃t���O���N���A����Ă��邩�m�F����
	*/
	bool IsCleared(const typename ENUM_T::_Ret ret) const {
		return !IsSet(ret);
	};


	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret_base& Mask(const typename ENUM_T::_Ret ret) {
		val &= 1u << (unsigned char)ret;
		return *this;
	};


	/*---������Z�q---*/
	/**
		ret�̃r�b�g�݂̂��Z�b�g���ꂽ��Ԃɂ���
	*/
	Ret_base& operator =(const typename ENUM_T::_Ret ret) {
		val = 1u << (unsigned char)ret;
		return *this;
	};

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base& operator +=(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};


	/**
		ret�̃t���O���N���A����
	*/
	Ret_base& operator -=(const typename ENUM_T::_Ret ret) {
		return Clear(ret);
	};

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base& operator |=(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};

	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret_base& operator &=(const typename ENUM_T::_Ret ret) {
		return Mask(ret);
	};

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base& operator <<(const typename ENUM_T::_Ret ret) {
		return Set(ret);
	};


	/*---�Z�p���Z�q---*/
	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base operator +(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Set(ret);
	};

	/**
		ret�̃t���O���N���A����
	*/
	Ret_base operator -(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Clear(ret);
	};

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret_base operator |(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Set(ret);
	};

	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret_base operator &(const typename ENUM_T::_Ret ret) const {
		Ret_base temp = *this;
		return temp.Mask(ret);
	};


	/*---��r���Z�q---*/
	/**
		ret�̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
	*/
	bool operator ==(const typename ENUM_T::_Ret ret) const {
		if (val == 1u << (unsigned char)ret) return true;
		else return false;
	};

	/**
		ret�̃t���O�݂̂��Z�b�g����Ă��Ȃ����m�F����
	*/
	bool operator !=(const typename ENUM_T::_Ret ret) const {
		if (val != 1u << (unsigned char)ret) return true;
		else return false;
	};

	/**
		ret�̃t���O�����̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
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
		ret�̃t���O�ȉ��̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
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
		ret�̃t���O�𒴂���t���O���Z�b�g����Ă��邩�m�F����
	*/
	bool operator >(const typename ENUM_T::_Ret ret) const {
		return !operator<=(ret);
	};

	/**
		ret�̃t���O�ȏ�̃t���O���Z�b�g����Ă��邩�m�F����
	*/
	bool operator >=(const typename ENUM_T::_Ret ret) const {
		return !operator<(ret);
	};



	/*---Ret���m�̔�r���Z�q---*/
	/**
		val�����������m�F����
	*/
	bool operator ==(const Ret_base& rhs) const {
		if (val == rhs.val) return true;
		else return false;
	};

	/**
		val���قȂ邩�m�F����
	*/
	bool operator !=(const Ret_base& rhs) const {
		if (val != rhs.val) return true;
		else return false;
	};

	/**
		val�̑傫�����r����
	*/
	bool operator <(const Ret_base& rhs) const {
		if (val < rhs.val) return true;
		else return false;
	};

	/**
		val�̑傫�����r����
	*/
	bool operator <=(const Ret_base& rhs) const {
		if (val <= rhs.val) return true;
		else return false;
	};

	/**
		val�̑傫�����r����
	*/
	bool operator >(const Ret_base& rhs) const {
		if (val > rhs.val) return true;
		else return false;
	};

	/**
		val�̑傫�����r����
	*/
	bool operator >=(const Ret_base& rhs) const {
		if (val >= rhs.val) return true;
		else return false;
	};

private:
	/**
		ENUM_T::_Ret�ƑΉ�����t���O�f�[�^
	*/
	unsigned int val;

	/**
		������ENUM_T::_Ret����val�̒l���v�Z����
	*/
	template<class... Args> static constexpr unsigned char calVal(const typename ENUM_T::_Ret ret, const Args... args) {
		return calVal(args...) | 1u << (unsigned char)ret;
	};

	/**
		calVal�̍ċA�I���̂��߂̊֐�
	*/
	static constexpr unsigned char calVal() {
		return 0;
	}
};

#endif