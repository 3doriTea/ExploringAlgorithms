#pragma once

/// <summary>
/// 共通のデータ保持用
/// </summary>
/// <typeparam name="T">格納するデータ型</typeparam>
template<typename T>
class IDataList
{
public:
	IDataList() {}
	virtual ~IDataList() {}

	/// <summary>
	/// 要素を取り出す
	/// </summary>
	/// <returns>要素</returns>
	virtual T Out() = 0;

	/// <summary>
	/// 要素を入れる
	/// </summary>
	/// <param name="_element">要素</param>
	virtual void In(const T _element) = 0;

	/// <summary>
	/// 要素が入っていないかどうか
	/// </summary>
	/// <returns>要素が入っていない true / false</returns>
	virtual bool Empty() = 0;
};
