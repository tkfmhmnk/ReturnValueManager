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
		�߂�l�̃t���O�̈Ӗ����`����񋓌^�Bval�̊e�t���O�ƑΉ�����B
	*/
	enum _Ret : unsigned char {
		OK = 0,
		NG,
	};

	/**
		�R���X�g���N�^
	*/
	Ret();

	/**
		������_Ret�ɂ����val������������R���X�g���N�^
	*/
	template<class... Args> constexpr Ret(const Args... args) : val(calVal(args...)) {
	};

	unsigned int GetData();

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret& Set(const _Ret ret);

	/**
		ret�̃t���O���N���A����
	*/
	Ret& Clear(const _Ret ret);


	/**
		�S�ăt���O���N���A����
	*/
	Ret& ClearAll();

	/**
		ret�̃t���O���Z�b�g����Ă��邩�m�F����
	*/
	bool IsSet(const _Ret ret) const;

	/**
		ret�̃t���O���N���A����Ă��邩�m�F����
	*/
	bool IsCleared(const _Ret ret) const;

	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret& Mask(const _Ret ret);


	/*---������Z�q---*/
	/**
		ret�̃r�b�g�݂̂��Z�b�g���ꂽ��Ԃɂ���
	*/
	Ret& operator =(const _Ret ret);

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret& operator +=(const _Ret ret);

	/**
		ret�̃t���O���N���A����
	*/
	Ret& operator -=(const _Ret ret);

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret& operator |=(const _Ret ret);

	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret& operator &=(const _Ret ret);

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret& operator <<(const _Ret ret);


	/*---�Z�p���Z�q---*/
	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret operator +(const _Ret ret) const;

	/**
		ret�̃t���O���N���A����
	*/
	Ret operator -(const _Ret ret) const;

	/**
		ret�̃t���O���Z�b�g����
	*/
	Ret operator |(const _Ret ret) const;

	/**
		ret�̃t���O�ȊO���}�X�N����
	*/
	Ret operator &(const _Ret ret) const;


	/*---��r���Z�q---*/
	/**
		ret�̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
	*/
	bool operator ==(const _Ret ret) const;

	/**
		ret�̃t���O�݂̂��Z�b�g����Ă��Ȃ����m�F����
	*/
	bool operator !=(const _Ret ret) const;

	/**
		ret�̃t���O�����̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
	*/
	bool operator <(const _Ret ret) const;

	/**
		ret�̃t���O�ȉ��̃t���O�݂̂��Z�b�g����Ă��邩�m�F����
	*/
	bool operator <=(const _Ret ret) const;

	/**
		ret�̃t���O�𒴂���t���O���Z�b�g����Ă��邩�m�F����
	*/
	bool operator >(const _Ret ret) const;

	/**
		ret�̃t���O�ȏ�̃t���O���Z�b�g����Ă��邩�m�F����
	*/
	bool operator >=(const _Ret ret) const;


	/*---Ret���m�̔�r���Z�q---*/
	/**
		val�����������m�F����
	*/
	bool operator ==(const Ret& rhs) const;

	/**
		val���قȂ邩�m�F����
	*/
	bool operator !=(const Ret& rhs) const;

	/**
		val�̑傫�����r����
	*/
	bool operator <(const Ret& rhs) const;

	/**
		val�̑傫�����r����
	*/
	bool operator <=(const Ret& rhs) const;

	/**
		val�̑傫�����r����
	*/
	bool operator >(const Ret& rhs) const;

	/**
		val�̑傫�����r����
	*/
	bool operator >=(const Ret& rhs) const;

private:
	/**
		_Ret�ƑΉ�����t���O�f�[�^
	*/
	unsigned int val;

	/**
		������_Ret����val�̒l���v�Z����
	*/
	template<class... Args> static constexpr unsigned char calVal(const _Ret ret, const Args... args) {
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